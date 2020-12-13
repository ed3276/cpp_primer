#include <iostream>
#include <cstring>
using namespace std;

char* multiply(char* num1, char* num2);

int main()
{
    cout << "Hello world!" << endl;
    char buffer[]="Hello world!";
    char *pbeg=buffer,*pend=buffer+strlen(buffer)-1;
		    while(pbeg<pend)
            {
                char tmp = *pbeg;
                *pbeg++ = *pend;
                *pend-- = tmp;
            }
            cout << buffer;
    //cout << multiply("56789","98765");
    return 0;
}


void InsertStr(char** ppsrc, char* inStr, int pos, int *curLen)
{
    char *src = *ppsrc;
	int temp = 0, sign = 0;
	int length = strlen(inStr);
	for (int i = pos; i<pos+length&&i<*curLen; ++i)
	{
		temp = (inStr[i-pos] - '0') + (src[i] - '0') + sign;
		src[i] = temp % 10 + '0';
        sign = temp/10;
	}
	if (sign)
	{
	    int x = pos + length;
	    while(x<*curLen)
        {
            temp = src[x] - '0' + sign;
            src[x] = temp % 10 + '0'; sign = temp / 10;
            ++x;
        }
		if(sign&&x >= *curLen)
        {

            char *pnsrc = (char*)realloc(src,2**curLen*sizeof(char)),*nsrc=pnsrc;
            *nsrc++ = sign + '0';
            char *beg = src, *end = src+*curLen-1;
            while(beg!=end)
                *nsrc++ = *beg++;
            free(src);
            src = pnsrc;
            *ppsrc = src;
        }
	}
}
char* convolutionStr(char* num1, char* num2)
{
	int num1Size = strlen(num1);
	int num2Size = strlen(num2);
    if(num1Size==1&&num1[0]=='0') return "0";
    if(num2Size==1&&num2[0]=='0') return "0";
	int retSize = num1Size + num2Size - 1;
	//¼ÆËã¾í»ý
	int pos = 0;
	char buffer[20] = { 0 };
    int curLen = retSize + 1;
	char *ret = (char*)calloc(curLen, sizeof(char));
	for (int i = 0; i<retSize + strlength - 1; ++i) ret[i] = '0';
	for (int i = num2Size-1; i >= -num1Size+1; --i)
	{
		temp = 0;
        if(i<=0)
        {
            int s = num1Size+i<num2Size?num1Size+i:num2Size;
            for (int j = 0; j < s; j++)
                temp += (num1[s-j-1]-'0') * (num2[j]-'0');
        }
        else
        {
            int s = num1Size<num2Size-i?num1Size:num2Size-i;
            for (int j = 0; j < s; j++)
                temp += (num1[num1Size-j-1]-'0') * (num2[i+j]-'0');
        }
		sprintf(buffer, "%d", temp);
		{
		    char *pbeg=buffer,*pend=buffer+strlen(buffer)-1;
		    while(pbeg<pend)
            {
                char tmp = *pbeg;
                *pbeg++ = *pend;
                *pend-- = tmp;
            }
		}
		//²åÈëret
		InsertStr(&ret, buffer, pos++,&curLen);
	}
	return ret;
}
char* multiply(char* num1, char* num2) {
    char *ret = NULL;
    if(strlen(num1)<strlen(num2))
        ret = convolutionStr(num1, num2);
    else
        ret = convolutionStr(num2, num1);
	return ret;
}

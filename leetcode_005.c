一  题目：
Longest Palindromic Substring(最长回文字符串)

二  题目要求：
	给定一个字符串，找出最长回文字符子串，给定的字符串长度不超过1000
	
三	题目分析：
/*
** 回文字符串：左右2边以中间字符为中心对称的字符串
**
** 方法：跟上一题有相似之处 2个指针，用一个指针指向中心的字符，向左右2边移动
*/

四	编写代码：

class Solution {
public:
    string longestPalindrome(string s) {
             
        /*    对传进来的字符串进行条件筛选 长度不能是空和小于1也不能大于1000  */
        
        if ( s.size() <= 1 )
        {
            return s;
        }
        
        if ( s.size() > 1000 )
        {
            return NULL;
        }
        
        /*     初始化变量和赋值   */
        
        int string_left              = 0;
        int string_right             = 0;
        int length_longest_substring = 0;
		int string_length            = s.size();
        string Longest_Palindromic_Substring;
        /*      主题函数    */

        for(int i = 1;i < string_length;i++)
        {
			 /*   寻找以i为中心的奇数长度的回文 比如：aa,bb型的  */ 
            string_left  = i - 1;
            string_right = i + 1;
            while((string_left >= 0) && (string_right < string_length) && (s[string_left] == s[string_right]))
                string_left--, string_right++;
            
            if ( length_longest_substring < string_right - string_left -1 )
            {
                length_longest_substring = string_right - string_left -1;
                Longest_Palindromic_Substring = s.substr(string_left+1, length_longest_substring);
            }
            
			/*    以i-1,i为中点偶数长度的回文子串  比如：aba,bab型的  */  
            string_left  = i-1;
            string_right = i;
            while((string_left >= 0) && (string_right < string_length) && (s[string_left] == s[string_right]))
                string_left--, string_right++;
            
            if ( length_longest_substring < string_right - string_left -1 )
            {
                length_longest_substring = string_right - string_left -1;
                Longest_Palindromic_Substring = s.substr(string_left+1, length_longest_substring);
            }
        }
        
        return Longest_Palindromic_Substring;
    }
};
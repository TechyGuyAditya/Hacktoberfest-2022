class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        // If the length of the palindrome is one thene even replacing it with any other character also gives a palindrome so in that case the result is none
        if (palindrome.length() == 1)
            return "";
        // Counting the number of a's
        int count_a = 0;
        // If the string contains all a's expect the middle one if it is odd then last occurrence of a can be changed to b which is the least lexicographically ordered
        for (int i = 0; i < palindrome.length(); i++)
        {
            if (palindrome[i] == 'a')
                count_a++;
        }

        // Checking the number of a's and the length of the palindrome
        if (count_a == palindrome.length() - 1 and palindrome.length() % 2 != 0)
        {
            palindrome[palindrome.length() - 1] = 'b';
            return palindrome;
        }

        // If the string contains any other character which can be replaced then it will get replaced with a which will be the least possible that can be formed
        for (int i = 0; i < palindrome.length(); i++)
        {
            if (palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                return palindrome;
            }
        }

        // If we got until here that means the case is that the string contains all a's and the length of the palindrome is even so replacing it's last character
        palindrome[palindrome.length() - 1] = 'b';

        // Returning the palindrome
        return palindrome;
    }
};
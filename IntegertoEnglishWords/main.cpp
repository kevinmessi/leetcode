#include <iostream>

using namespace std;

const char *kTeens[20] =
{
    "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
    "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
};
const char *kTies[8] = { "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
const char *kMore[4] = { "", " Thousand", " Million", " Billion" };

string TenToWords(int num)
{
    if (num < 20) return kTeens[num];
    int ten = num / 10, one = num % 10;
    string words = kTies[ten - 2];
    if (one) words.append(" ").append(kTeens[one]);
    return words;
}

string HundredToWords(int num)
{
    string words;
    int hundred = num / 100, ten = num % 100;
    if (hundred) words.append(kTeens[hundred]).append(" Hundred");
    if (ten) words.append(hundred ? " " : "").append(TenToWords(ten));
    return words;
}

string numberToWords(int num)
{
    if (num == 0) return "Zero";
    string words;
    for (int i = 0; num > 0; num /= 1000, ++i)
    {
        int chunk = num % 1000;
        if (chunk > 0)
            words = HundredToWords(chunk) + kMore[i] + (words.empty() ? "" : " ") + words;
    }
    return words;
}

int main()
{
    cout << numberToWords(123) << endl;
    cout << numberToWords(12345) << endl;
    cout << numberToWords(1234567) << endl;
    return 0;
}

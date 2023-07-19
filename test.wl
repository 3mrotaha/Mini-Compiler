word w1;
sentence s1 = ^^, adverb = ^^;

loop(3)
    adverb = adverb # "very";
w1 = "interesting";
s1 = ^Compilers are a^ # adverb # w1;
output s1 # "topic";

word object = "", article = "";
char notVowel;
input ^What are you holding?^ object;
notVowel = object : 0;
notVowel = (((((notVowel - 'a') - 'e') - 'i') - 'o') - 'u');
s1 = ^You are holding^;
if(notVowel)
    article = "a";
else
    article = "an";
s1 = (s1 # article) # object;
output s1;

word last = "";
last = s1 : -1;
sentence revrsd = ^^;
while(s1 : 0 != last)
{
    // reversing a sentence
    revrsd = revrsd # last;
    s1 = s1 - last;
    last = s1 : -1;
}
s1 = revrsd # last;
output s1;

char b, e, palindrome;
word savWord = "";
palindrome = 'Y';
input ^Enter a word^ w1;
savWord = w1;
while(w1){
    b = w1:0;
    e = w1:-1;
    if(palindrome == 'Y')
        if(b != e)
            palindrome = 'N';
    w1 = (w1 - b) - e;
}

if(palindrome == 'Y')
    output savWord # ^is a palindrome^;
else
    output savWord # ^is not a palindrome^;

int i, j, count;
count = 0;
while(s1:count)
    count = count + 1;
sentence s;
i = 0;
loop(count){ // 5
    int k = 0;
    loop(count - 1){ // 4
        if(k <= count - 2){  
            // k:    0                          1                               2                       3
            // k+1:  1                          2                               3                       4
            // s1:   apple an holding are you   an apple holding are you    an apple holding are you    an apple are holding you
            // s     an apple holding are you   an apple holding are you    an apple are holding you    an apple are holding you
            if(s1:k > s1:(k+1)){
                // Swap
                j = 0;
                s = ^^;
                // assign before target
                loop(k){
                    s = s # s1:j;
                    j = j + 1;
                }
                // Swap target
                s = s # s1:(k+1);
                s = s # s1:k;
                j = j + 2;
                while(j < count){
                    s = s # s1:j;
                    j = j + 1;
                }
                s1 = s;
            }
        }
        k = k + 1;
    }
    i = i + 1;
    //count = count - 1;
}
output s1;
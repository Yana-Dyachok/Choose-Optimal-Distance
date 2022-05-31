/*Ділан і Кейт хочуть подорожувати між кількома містами А, В, С.... Кейт має на аркуші паперу список відстаней між цими містами. ls = [51, 56, 58, 59, 61]. Ділан втомився їздити, і він каже Кейт, що не хоче їхати більше t = 174 миль, і він відвідає лише 3 міста. 
Відстань, а значить, які міста вони оберуть, щоб сума відстаней була якнайбільша, щоб догодити Кейт і Ділану?
Приклад: Маючи список ls та 3 міста для відвідування, вони можуть зробити вибір між: [51,56,58], [51,56,59], [51,56,61], [51,58,59], [51, 58,61], [51,59,61], [56,58,59], [56,58,61], [56,59,61], [58,59,61].
Тоді суми відстаней становлять 165, 166, 168, 168, 170, 171, 173, 175, 176, 178.
Найбільшою можливою сумою з урахуванням обмеження у 174 є 173, а відстані до 3 відповідних міст – [56, 58, 59].Функція chooseOptimalDistance приймає параметри:
t (максимальна сума відстаней, ціле число> = 0), k (кількість міст, які потрібно відвідати, k> = 1), ls (список відстаней, всі відстані є позитивними або нульовими цілими числами, і цей список містить щонайменше один елемент).
Функція повертає "найкращу" суму, тобто найбільшу можливу суму k відстаней, менших або рівних заданої межі t, якщо ця сума існує або якщо не існує - null. Примітка: не змінюйте змінну ls.*/
#include <iostream>
#include <stdio.h>
using namespace std;
int next_combination(size_t* I, size_t k, size_t n);
int chooseOptimalDistance(int Is[5], int t, int K, size_t* I, size_t i, size_t k, size_t n);

int main()
{
    int Is[5]={51,56,58,59,61};
    int t = 0, K = 1;
    cout << "Enter your distance:" << endl;
    cin >> t;
    cout << "Enter how many cities u want to visit (chose from 1 to 5):" << endl;
    cin >> K;
   size_t I[5];
   size_t i=0, k=0, n;
   n = sizeof(Is) / sizeof(Is[0]);
   cout<<"Optimal distance is =" << chooseOptimalDistance(Is, t, K, I, i, k, n) << endl;
   }

int next_combination(size_t* I, size_t k, size_t n)
{
    size_t i, j;
    i = k - 1;
    while (I[i] == (n - k + i)) {
        --i;
        if (i == (size_t)-1) {
            for (i = 0; i < k; i++)
                I[i] = i;
            return(0);
        }
    }
    I[i] += 1;
    for (j = i + 1; j < k; j++)
        I[j] = I[i] + j - i;
    return(1);
}


int chooseOptimalDistance(int Is[5], int t, int K, size_t* I, size_t i, size_t k, size_t n) {
    int sum1 = 0, sum2 = 0;
    int sum = 0, d = 0, Sum = 0;
    int* arr = new int[d];
    for (int i = 0; i < K; i++)
    {
        sum1 += Is[i];
    }
    for (int i = n; i > n - K; i--)
    {
        sum2 += Is[i];
    }
    if (t >= sum1 or t <= sum2) {
        for (k = K; k <= K; k++) {
            for (i = 0; i < k; i++)
                I[i] = i;
            do {
                for (i = 0; i < k; i++)
                    sum += Is[I[i]]; d++;
                Sum = sum; sum = 0;
                arr[d] = Sum;
            } while (next_combination(I, k, n));
        }
        for (int s = d; s >= 1; s--)
        {
            if (arr[s] <= t)  return arr[s];
        }
    }
    else return 0;
    delete[]arr;
}
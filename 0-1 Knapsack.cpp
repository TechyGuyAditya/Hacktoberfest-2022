#include <stdio.h>
int weight[] = {80,140,70,300,500,250,400,700,350};
int price[] = {2000,2500,1900,4000,6000,3000,7000,6500,3500};
void Greedy_Knapsack(int M,int n) {
int current_value;
float total_value;
int i, maximum;
int used[n];
for (i = 0; i < n; ++i){
   used[i] = 0;
 }
current_value = M;
while (current_value > 0)
{
   maximum = -1;
   for (i = 0; i < n; ++i)
      if ((used[i] == 0) &&((maximum == -1) || (price[i]*1.0/weight[i] > price[maximum]*1.0/weight[maximum])))
      maximum = i;
    used[maximum] = 1;
    current_value -= weight[maximum];
    total_value += price[maximum];
    if (current_value >= 0)
      printf("Add object %d (%d, %d weight). Space left: %d.\n", maximum +1, price[maximum], weight[maximum], current_value);
    else {
    total_value -= price[maximum];
    }
  }
printf("Filled the knapsack with items worth %.2f.\n", total_value);
}
int main()
{
int M = 1000;
int n = 9;
Greedy_Knapsack(M,n);
}

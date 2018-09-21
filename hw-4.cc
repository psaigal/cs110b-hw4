#include <iostream>
using namespace std;

void initializeArr(int arr[]) 
{ 
    for (int i = 0; i <= 21; i++)
    {
        arr[i] = i + 1;
    } 
} 

void displayNums(int arr[], int count) 
{ 
   for (int i = 0; i <= count; i++)
    {
        cout << arr[i] << endl;
    } 
    cout << endl;
} 

void distributeCards(int arr1[], int arr2[], int arr3[], int allNums[]) 
{ 
   for (int i = 0, z = 0; i <= 20; i+=3, z += 1)
    {
        arr1[z] = allNums[i];
        arr2[z] = allNums[i+1];
        arr3[z] = allNums[i+2];
    } 
} 

void shuffleCards(int arr1[], int arr2[], int arr3[], int allNums[], int middle) 
{ 
    for (int i = 0, x = 0, y = 7, z = 14; 
        i <= 6, x < 7, y < 14, z < 21; 
        i += 1, x += 1, y += 1, z += 1)
    {
        if (middle == 1) {
            allNums[x] = arr2[i];
            allNums[y] = arr1[i];
            allNums[z] = arr3[i];
        }
        else if(middle == 2)
        {
            allNums[x] = arr1[i];
            allNums[y] = arr2[i];
            allNums[z] = arr3[i];
        }
        else 
        {
            allNums[x] = arr1[i];
            allNums[y] = arr3[i];
            allNums[z] = arr2[i];
        }
        
    } 
} 

void checkCard(int arr[])
{
    cout << "Is " << arr[10] << " your number?" << endl << endl;
}

void playGame(int pile_one[], int pile_two[], int pile_three[], int all_nums[])
{
    int pileChosen;
    int count = 0;
    while (count < 3)
    {
        distributeCards(pile_one, pile_two, pile_three, all_nums);
        cout << "Pile 1" << endl;
        displayNums(pile_one, 6);

        cout << "Pile 2" << endl;
        displayNums(pile_two, 6);

        cout << "Pile 3" << endl;
        displayNums(pile_three, 6);

        cout << "Please choose a pile (1, 2, or 3)." << endl;
        cin >> pileChosen;
        cout << endl;

        shuffleCards(pile_one, pile_two, pile_three, all_nums, pileChosen);
        
        count += 1;
    }
    checkCard(all_nums);
}


int main() {
  int allNums[21];
  int pile_one[7];
  int pile_two[7];
  int pile_three[7];
  int willPlay;

  initializeArr(allNums);

  cout << "Think of one of the numbers shown below." << endl;
  displayNums(allNums, 20);

  cout << "Press 0 to play the game" << endl;
  cin >> willPlay;
  cout << endl;

  if (willPlay == 0)
  {
    playGame(pile_one, pile_two, pile_three, allNums);
  }
}

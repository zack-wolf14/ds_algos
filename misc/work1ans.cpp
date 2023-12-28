//****************************************************Work 1 - By Charanpreet Singh Narula*******************************************
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

struct Element
{
    int value1;
    int value2;
};

class Classify
{
    int sumAwesome = 0;
    int sumLessAwesome = 0;
    int sumPhenomenal = 0;

public:
    vector<Element> mainList;         // declaring Vectors for each type of elements
    vector<Element> awesomeList;
    vector<Element> lessAwesomeList;
    vector<Element> phenomenalList;

    Classify(int length, int range)
    {
        srand(time(0));               // changing the seed of random integers using the seconds 
        mainList[length];            

        for (int i = 0; i < length; i++)
        {
            Element input;
            input.value1 = rand() % range;  // assigning value to the variables of the Element srtucture in the range of remainders
            input.value2 = rand() % range;
            mainList.push_back(input); // adding the elements in the main list

            int sum = mainList[i].value1 + mainList[i].value2;

            if (sum == 10 && !(mainList[i].value1 & 1)) // checking the condition for phenomenal elements, sum == 10 and even numbers using bitwise operator
                phenomenalList.push_back(mainList[i]);
            else if (sum == 10)                         // condition for awesome element
                awesomeList.push_back(mainList[i]);
            else if (sum == 5)                          // condition for less awesome element
                lessAwesomeList.push_back(mainList[i]);
        }
    }

    long long get_sum(bool awe, bool lessAwe, bool pheno)  // calculating the sum of all the awesome, less awesome and phenomenal elements, if sum of one of the lists already exists then using it instead of calculating again
    {                                                                       
        long long sum = 0;
        if (awe)
        {
            if (!sumAwesome)                
                for (Element temp : awesomeList)
                    sumAwesome += temp.value1 + temp.value2;
            sum += sumAwesome;
        }

        if (lessAwe)
            if (!sumLessAwesome)
            {
                for (Element temp : lessAwesomeList)
                    sumLessAwesome += temp.value1 + temp.value2;
                sum += sumLessAwesome;
            }
            else
                sum += sumLessAwesome;

        if (pheno)
            if (!sumPhenomenal)
            {
                for (Element temp : phenomenalList)
                    sumPhenomenal += temp.value1 + temp.value2;
                sum += sumPhenomenal;
            }
            else
                sum += sumPhenomenal;

        return sum;
    }

    void print() // printing all the elements in each list 
    {
        cout << "\n\nmainList : ";
        for (Element i : mainList)
            cout << " {" << i.value1 << "," << i.value2 << "} ";

        cout << "\n\nawesomeList : ";
        for (Element i : awesomeList)
            cout << " {" << i.value1 << "," << i.value2 << "} ";

        cout << "\n\nlessAwesomeList : ";
        for (Element i : lessAwesomeList)
            cout << " {" << i.value1 << "," << i.value2 << "} ";

        cout << "\n\nphenomenalList : ";
        for (Element i : phenomenalList)
            cout << " {" << i.value1 << "," << i.value2 << "} ";
    }
};

int main()
{
    Classify c(20, 10); // taking parameters length of list and range of numbers respectively
    c.print();
    cout << "\n\nYour Sum is -> " << c.get_sum(1, 1, 1)<<endl;  // Takes boolean arguments to print the respective sum- (Awesome, lessAwesome, Phenomenal)

    return 0;
}
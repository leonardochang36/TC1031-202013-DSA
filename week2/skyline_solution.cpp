// You are handed a scenic black-and-white photo of the skyline of a city. The photo
// is n-pixels tall and m-pixels wide, and in the photo, buildings appear as black (pixel value 0) and sky
// background appears as white (pixel value 1). In any column, all the black pixels are below all the
// white pixels. In this problem, you will design an efficient algorithm that finds the location of a tallest
// building in the photo.
//
// The input is an n x m matrix, where the buildings are represented with 0s, and the sky is 
// represented by 1s. The output is an integer representing the location of a tallest building. 
// For example, for the input 5 x 6 matrix below, a tallest building has height 5 and is 
// in location 3 (assuming we are 0-indexing). Thus the output is 3.
//
//     1 1 1 0 1 1 
//     1 1 0 0 0 1 
//     0 1 0 0 0 1 
//     0 1 0 0 0 1 
//     0 0 0 0 0 1 
//
// a) Find and implement (in C++) an algorithm that finds a tallest building in time O(m log n).
// b) Find and implement (in C++) an algorithm that finds a tallest building in time O(m + n).
//
// Note: Add as a comment block in your code a brief justification of the runtime of each algorithm.


#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>
using namespace std;

#define m 11
#define n 9

// cálculo de la altura de un edificio en O(logn)
// nótese que es un caso especial de búsqueda binaria
// donde no estamos buscando un elemento en particular
// sino la posición donde comienza la secuencia 1-0
// o sea que termina el cielo y comienza el edificio
int building_height(int pic[n][m], int col, int begin, int end)
{
	int i = (begin + end) / 2;
    // paso base 1: 
    // si encuentro secuencia 1-0, devuelvo indice+1 (cantidad)
	if (pic[i][col] == 1 && pic[i+1][col] == 0)
		return i+1;
    
    // paso base 2:
    // si no se encontró secuencia 01, o sea son todos 0s o 1s
    // devuelvo 0 o cantidad de 1s
    if (begin == end)
        return pic[i][col] * n; 

    // paso recursivo
	else if (pic[i][col] == 0)
		return building_height(pic, col, begin, i-1);
	else
		return building_height(pic, col, i+1, end);
}

// búsqueda del edificio más alto en O(mlogn)
// para cada edificio m, se calcula su altura en O(logn)
int tallest_building_v1(int pic[n][m])
{
    int tallest = 0;
    int bigger_height = 0;
	for (int i = 0; i < m; i++)
	{
		int h = n - building_height(pic, i, 0, n-2);
        if (h > bigger_height)
        {
            bigger_height = h;
            tallest = i;
        }
	}
    return tallest;
}

// búsqueda del edificio más alto en O(mlogn), versión 2
// es más eficiente ya que cuando encuentra un edificio que se sabe 
// es menos alto que otro, no se vuelve a visitar, el vector candidates 
// almacena los posibles candidatos que van quedando
void tallest_building_v2(int pic[n][m], vector<int> &candidates, map<int, int> &heights, int begin, int end)
{
    if (end < begin || candidates.empty())
        return;

	int i = (begin + end) / 2;

    bool up = false;
    for (int k = candidates.size()-1; k >= 0 ; k--)
    {        
        if (pic[i][candidates[k]] == 1) 
        {
            //  if is building limit
            if (pic[i+1][candidates[k]] == 0)
                heights[candidates[k]] = n - i - 1;

            if (up || !heights.empty())
                candidates.erase(candidates.begin() + k);          
        }
        else
        {
            up = true;
            if (i == 0) 
            {
                heights[candidates[k]] = n;
                candidates.erase(candidates.begin() + k);          
            }
        }
    }

    if (up)
        tallest_building_v2(pic, candidates, heights, begin, i);
    else
        tallest_building_v2(pic, candidates, heights, i+1, end);    
}

// búsqueda del edificio más alto en O(m + n), versión 3
// ejemplo de recorrido, posiciones visitadas entre | |
//  1  1  1 |0||1||1|
// |1||1||0||0| 0  1
// |0| 1  0  0  0  1
// |0| 1  0  0  0  1
// |0| 0  0  0  0  1
int tallest_building_v3(int pic[n][m])
{
    int bi = 0, hj = 0;
    int tallest = -1, max_h = n;
    int i = 0, j = n-1;
    for (; i < m; i++)
    {
        for (; j >= 0; j--)
        {
            if (pic[j][i] == 1) 
            {
                if (max_h > j) 
                {
                    tallest = i;
                    max_h = j;
                }
                break;
            }
            else if (j == 0)
            {
                tallest = i;
                i = m;
                break;
            }            
        }        
    }
    return tallest;
}

void random_fill_building(int (&pic)[n][m])
{
    srand(time(0));
    for (int i = 0; i < m; i++)
    {
        int h = rand() % n;
        for (int j = 0; j < n; j++)
        {
            pic[j][i] = j < h ? 1 : 0;
        }        
    }
}

string print_building(int pic[n][m])
{
    string out = "";
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            if (pic[j][i] == 0) 
                out += "0 ";
            else
                out += "1 ";
        }
        out += "\n";
    }
    for (int i = 0; i < m; i++)
    {
        out += "--";
    }
    out += "\n";
    for (int i = 0; i < m; i++)
    {
        out += to_string(i) + " ";
    }
    out += "\n";
    return out;    
}


int main()
{
    int building[n][m];
    random_fill_building(building);
    string b_str = print_building(building);
    cout << b_str;

    //-- Version 1 
    int tallest = tallest_building_v1(building);
    cout << "------" << endl;
    cout << tallest << endl;    

    //-- Version 2 
    vector<int> candidates;
    for(int i = 0; i < m; i++)
        candidates.push_back(i);
    map<int, int> heights;
    tallest_building_v2(building, candidates, heights, 0, n-1);    
    int max_i = -1, max_h = -1;
    for (auto const& x : heights){
        if (x.second > max_h){
            max_h = x.second;
            max_i = x.first;
        }
    }
    cout << "------" << endl;
    cout << max_i << endl;

    //-- Version 3
    cout << "------" << endl;
    cout << tallest_building_v3(building) << endl;

    return 0;
}
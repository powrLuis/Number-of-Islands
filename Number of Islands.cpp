// Number of Islands.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
using namespace std;
using Matrix = std::vector<std::vector<char>>;
using Vertex = std::pair<int,int>;

vector<Vertex> vecinos(Vertex v, Matrix& grid)
{
    int m = grid.size();
    vector<Vertex> result;
    //izquierda
    if (v.first>=1)
    {
        result.push_back(Vertex(v.first - 1, v.second));
    }
    //arriba
    if (v.second>=1)
    {
        result.push_back(Vertex(v.first, v.second - 1));
    }
    //derecha
    if (v.first+1<grid.size())
    {
        result.push_back(Vertex(v.first + 1, v.second));
    }
    //abajo
    if (v.first< grid.size()&& v.second+1<grid[v.first].size())
    {
        result.push_back(Vertex(v.first, v.second+1));
    }
    return result;
}

int numIslands(Matrix& grid) {
    
    //auto vecino = vecinos(v, grid);
    return 0;
}

void matrix_dfs(Matrix& grid)
{
    set<Vertex> visitados;
    stack<Vertex> pila;
    Vertex root(0, 0);
    pila.push(root);
    while (!pila.empty())
    {
        auto current = pila.top();
        pila.pop();
        if (visitados.find(current) != visitados.end()) {
            continue;
        }
        cout << "current: " << current.first << ", " << current.second;
        cout << " valor: " << grid[current.first][current.second] << endl;
        cout << " vecinos: ";
        for (auto v : vecinos(current, grid))
        {
            cout << "(" << v.first << ", " << v.second << ")";
            pila.push(v);
        }
        cout << endl;
        visitados.insert(current);
    }
}

void matrix_bfs(Matrix& grid)
{
    set<Vertex> visitados;
    queue<Vertex> cola;
    Vertex root(0, 0);
    cola.push(root);
    while (!cola.empty())
    {
        auto current = cola.front();
        cola.pop();
        if (visitados.find(current) != visitados.end()) {
            continue;
        }
        cout << "current: " << current.first << ", " << current.second;
        cout << " valor: " << grid[current.first][current.second] << endl;
        cout << " vecinos: ";
        for (auto v : vecinos(current, grid))
        {
            cout << "(" << v.first << ", " << v.second << ")";
            cola.push(v);
        }
        cout << endl;
        visitados.insert(current);
    }
}

int main()
{
    Matrix m = { {'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'} };
    matrix_bfs(m);

    std::cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

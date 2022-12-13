// AUTHOR: Juan García Santos
// DATE: 04/10/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 4.0
// SUBJECT: AI
// PRACTICE Nº: 1
// Compilation: make
// Execution: ./simulation
// Especificaciones de la clase mundo

#include "include/world.h"

//Constructores

World::World(){
    row = 10;
    col = 10;
    size = 100;
    world.resize(10);
    for(unsigned int i = 0; i < world.size(); i++) {
        world[i].resize(10);
    }
}

World::World(int row_, int col_) {

    row = row_, col = col_;
    size = row * col;
    world.resize(row);
    for(unsigned int i = 0; i < world.size(); i++){
        world[i].resize(col);
    }
}

World::World(int row_, int col_, int obstacle_percentage, int obstacle_type){ //inicializamos un mundo con obstaculos 
    
    int x, y;

    row = row_, col = col_;
    size = row * col;

    world.resize(row);
    for(unsigned int i = 0; i < world.size(); i++) {
        world[i].resize(col);
    }

    int obstacle_quantity = size * obstacle_percentage / 100;
    switch (obstacle_type) {
    case 0:

        srand(time(NULL)); 
        for(int i = 0; i < obstacle_quantity; i++) {
            int random_row = rand()%(world.size() - 0) + 0;
            int random_col = rand()%(world[random_row].size());

            SetWorldValue(true, random_row, random_col);
        }
        break;
    


    case 1:
        for(int i = 0; i < obstacle_quantity; i++) {
            do {
                std::cout << "Introduzca la coordenada X del obstaculo " << i+1 << " : ";
                std::cin >> x;
                while ((x < 0) || (x > row)) {
                    std::cout << "Esa coordenada X no está dentro del mundo previamente definido. Ojito Cuidado" << std::endl;
                    std::cout << "Introduzca una coordenada entre " << 0 << " y " << row << std:: endl;
                std::cin >> x;
                }

                std::cout << "Introduzca la coordenada Y del obstaculo " << i+1 << " : ";
                std::cin >> y;
                while ((y < 0) || ( y > col)) {
                    std::cout << "Esa coordenada Y no está dentro del mundo previamente definido. Ojito Cuidado" << std::endl;
                    std::cout << "Introduzca una coordenada entre " << 0 << " y " << col << std:: endl;
                    std::cin >> y;
                }
                
            } while (GetWorldValue(x, y) == true); //mientras la casilla ya esté ocupada

            SetWorldValue(true, x, y);
        }

        break;
    
    case 2:
        try {
        std::ifstream input_file("obstacle.txt");
        std::string read, number1, number2;
        unsigned movement = 0;

        if (!input_file.is_open()) throw 0;
        
        while(getline(input_file, read)) {
            if (read[0] != '/' && read[1] != '/') {

            for(; movement < read.size(); movement ++) {
                if(read[movement] != ',') {
                    number1.push_back(read[movement]);
                }
                else{
                    movement ++;
                    break; 
                }
            }
            for(; movement < read.size(); movement ++) {
                number2.push_back(read[movement]);
            } 

            x = stoi(number1);
            y = stoi(number2);
            number1.clear();
            number2.clear();
            movement = 0;

            if((x < 0) || (x > row) || (y < 0) || ( y > col)) throw 1;
            SetWorldValue(true, x, y);
            }
        }          
        input_file.close();

    }
    catch(int& error) {
        switch (error)
        {
        case 0:
            std::cout<<"No se pudo abrir el archivo - obstacle.txt"<<std::endl;
            break;
        
        case 1:
            std::cout<<"Datos mal introducidos"<<std::endl;
            break;
        }
    }

    break;
    }   
}

World::World(int row_, int col_, int obstacle_percentage, int obstacle_type, int heuristic_type){ //inicializamos un mundo con tipos de heuristicas y tipos de introducion de obstaculos
    int x, y;
    row = row_, col = col_;
    size = row * col;

    world.resize(row);
    for(unsigned int i = 0; i < world.size(); i++) {
        world[i].resize(col);
    }

    switch(heuristic_type) {
        case 0:
            //heuristica = new d_manhattan;

        case 1:
            //heuristica = new d_euclidea;

        case 2:
           // heuristica = new d_tchebysev;
           ;
    }

    int obstacle_quantity = size * obstacle_percentage / 100;
    switch (obstacle_type) {
    case 0:

        srand(time(NULL)); 
        for(int i = 0; i < obstacle_quantity; i++) {
            int random_row = rand()%(world.size());
            int random_col = rand()%(world[random_row].size());

            SetWorldValue(true, random_row, random_col);
        }
        break;
    


    case 1:
        for(int i = 0; i < obstacle_quantity; i++) {
            do {
                std::cout << "Introduzca la coordenada X del obstaculo " << i+1 << " : ";
                std::cin >> x;
                while ((x < 0) || (x > row)) {
                    std::cout << "Esa coordenada X no está dentro del mundo previamente definido. Ojito Cuidado" << std::endl;
                    std::cout << "Introduzca una coordenada entre " << 0 << " y " << row << std:: endl;
                std::cin >> x;
                }

                std::cout << "Introduzca la coordenada Y del obstaculo " << i+1 << " : ";
                std::cin >> y;
                while ((y < 0) || ( y > col)) {
                    std::cout << "Esa coordenada Y no está dentro del mundo previamente definido. Ojito Cuidado" << std::endl;
                    std::cout << "Introduzca una coordenada entre " << 0 << " y " << col << std:: endl;
                    std::cin >> y;
                }
                
            } while (GetWorldValue(x, y) == true); //mientras la casilla ya esté ocupada

            SetWorldValue(true, x, y);
        }

        break;
    
    case 2:
        try {
        std::ifstream input_file("obstacle.txt");
        std::string read, number1, number2;
        unsigned movement = 0;

        if (!input_file.is_open()) throw 0;
        
        while(getline(input_file, read)) {
            if (read[0] != '/' && read[1] != '/') {

            for(; movement < read.size(); movement ++) {
                if(read[movement] != ',') {
                    number1.push_back(read[movement]);
                }
                else{
                    movement ++;
                    break; 
                }
            }
            for(; movement < read.size(); movement ++) {
                number2.push_back(read[movement]);
            } 

            x = stoi(number1);
            y = stoi(number2);
            number1.clear();
            number2.clear();
            movement = 0;

            if((x < 0) || (x > row) || (y < 0) || ( y > col)) throw 1;

            SetWorldValue(true, x, y);
            }
        }          
        input_file.close();

    }
    catch(int& error) {
        switch (error)
        {
        case 0:
            std::cout<<"No se pudo abrir el archivo - obstacle.txt"<<std::endl;
            break;
        
        case 1:
            std::cout<<"Datos mal introducidos"<<std::endl;
            break;
        }
    }

    break;
    }   
}


//Destructor

World::~World(){
}

//Getters y Setters

bool World::GetWorldValue(int i, int j) {
    try {
       return world[i][j].GetValue();
    }
    
    catch(...){
        throw std::exception();
    }
}

void World::SetRow(int row_) {
    row = row_;
}

void World::SetColumn(int column_) {
    col = column_;
}

void World::SetSize(int size_) {
    size = size_;
}

void World::SetWorldValue(bool value_, int i, int j) {
    world[i][j].SetValue(value_);
}

void World::ToggleWorldValue(int i, int j){
    
   if(world[i][j].GetValue() == false){
        world[i][j].SetValue(true);
   }
   else {
        world[i][j].SetValue(false);
   }  
}


void World::SetWorld(std::vector<std::vector<Cell>>& new_world){

    world.resize(new_world.size());

    for(unsigned int i = 0; i < world.size(); i++){
        world[i].resize(new_world[i].size());
        for(unsigned int j = 0; j < world[i].size(); j++){
            world[i][j] = new_world[i][j];
        }
    }
}

void World::PrintWorld(void) {
    PrintHorizontalWall();
    for(unsigned int i = 0; i < world.size(); i++) {
        std::cout << "|";
        for(unsigned int j = 0; j < world[i].size(); j++) {
            if (GetWorldValue(i,j))
                std::cout << " ";
        }
        std::cout << "|" << std::endl;
    }
    PrintHorizontalWall();
}

void World::PrintHorizontalWall(void) {   
    for(unsigned int i = 0; i < world[0].size() + 2; i++) {
        std::cout << termcolor::on_color<0, 0, 0> << "-" << termcolor::reset;
    }
    std::cout << std::endl;
}

/*void World::Update(std::vector<Vehicle>& vehicle) {

    for(int i = 0; i < vehicle.size(); i++) {
        if ((GetWorldValue(vehicle[i].GetRow(), vehicle[i].GetColumn())) == false){ // casilla blanca
            SetWorldValue(true, vehicle[i].GetRow(), vehicle[i].GetColumn());
        }
        else {
            SetWorldValue(false, vehicle[i].GetRow(), vehicle[i].GetColumn()); //casilla negra
        } 
    }
}
*/

void World::PrintGrid(Vehicle* vehicle){
    //PrintHorizontalWall();
        for(unsigned int i = 0; i < world.size(); i++) { 
            //std::cout << termcolor::on_color<0, 0, 0> << "|" << termcolor::reset;
            for(unsigned int j = 0; j < world[i].size(); j++) {
                if((i == unsigned(vehicle->GetRow())) && (j == unsigned(vehicle->GetColumn())))
                    vehicle->PrintDirection();
                else if ((i == unsigned(vehicle->GetDestinationRow())) && (j == unsigned(vehicle->GetDestinationColumn()))) { 
                    std::cout << termcolor::on_red << "X" << termcolor::reset;
                }
                else { 
                    if (GetWorldValue(i, j)) 
                        std::cout << termcolor::on_color<0, 0, 0> << " " << termcolor::reset;
                    else
                        std::cout << termcolor::on_white << " " << termcolor::reset;
                }
            }
            std::cout << "\n";
            //std::cout << termcolor::on_color<0, 0, 0> << "|" << termcolor::reset << std::endl;
        }
    //PrintHorizontalWall();
}

bool World::VehicleOut(Vehicle* vehicle) {
    bool condition = false;
    if((unsigned(vehicle->GetRow()) >= world.size()) || (unsigned(vehicle->GetColumn()) >= world.size()) || (vehicle->GetRow() < 0) || (vehicle->GetColumn() < 0))
        condition = true;
    return condition;
}

void World::TryPosition(Vehicle* vehicle){
    try{
        Cell temp;
        temp = GetCell(vehicle->GetRow(), vehicle->GetColumn());
    }
    catch(std::exception()){
        std::cout << "el taxi se ha salido del mundo!!!" << std::endl;
        throw(std::exception());
    }
}

std::pair<std::vector<int>, std::vector<int>> World::Dijkstra(int origen) {
    std::vector<std::vector<int>> graph = Adjacency_Graph_4();
    std::vector<int> dist(size, __INT_MAX__);
    std::vector<int> prev(size, 0);
    std::vector<bool> visit(size, false);
    
    dist[origen] = 0;
    
    for (int i = 0; i < size; i++) {
        int u = extraer_min(dist, visit);
        visit[u] = true;
        for (int v = 0; v < size; v++) {
            if (!visit[v] && graph[u][v] && dist[u] != __INT_MAX__
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }
    return std::pair<std::vector<int>, std::vector<int>> (dist, prev);
}

std::vector<std::vector<int>> World::Adjacency_Graph_4() {
    std::vector<std::vector<int>> graph;
    graph.resize(size);
    
    for (int i = 0; i < size; i++) graph[i].resize(size);
    
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            graph[i][j] = 0;

    for (int i = 0; i < size; i++) {
        int x = i % row;
        int y = (i - x) / row;
        x -= row / 2;
        y -= col / 2;
        if (i + 1 < size && x + 1 <= row) if (!GetWorldValue(x + 1, y)) 
            graph[i][i + 1] = 1;
        if (i - 1 >= 0 && x - 1 >= 0) if (!GetWorldValue(x - 1, y)) 
            graph[i][i - 1] = 1;
        if (i - row >= 0 && y - 1 >= 0) if (!GetWorldValue(x, y - 1)) 
            graph[i][i - row] = 1;
        if (i + row < size && y + 1 <= col) if (!GetWorldValue(x, y + 1)) 
            graph[i][i + row] = 1;
    }

    return graph;
}

std::vector<std::vector<int>> World::Adjacency_Graph_8() {
    std::vector<std::vector<int>> graph;
    graph.resize(size);
    
    for (int i = 0; i < size; i++) graph[i].resize(size);
    
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            graph[i][j] = 0;

    for (int i = 0; i < size; i++) {
        int x = i % row;
        int y = (i - x) / row;
        x -= row / 2;
        y -= col / 2;
        if (i + 1 < size && x + 1 <= row) if (!GetWorldValue(x + 1, y)) 
            graph[i][i + 1] = 1;
        if (i - 1 >= 0 && x - 1 >= 0) if (!GetWorldValue(x - 1, y)) 
            graph[i][i - 1] = 1;
        if (i - row >= 0 && y - 1 >= 0) if (!GetWorldValue(x, y - 1)) 
            graph[i][i - row] = 1;
        if (i + row < size && y + 1 <= col) if (!GetWorldValue(x, y + 1)) 
            graph[i][i + row] = 1;
        if (i + 1 + row < size && x + 1 <= row && y + 1 <= col) if (!GetWorldValue(x + 1, y + 1)) 
            graph[i][i + 1 + row] = 1;
        if (i - 1 + row < size && x - 1 >= 0 && y + 1 <= col) if (!GetWorldValue(x - 1, y + 1)) 
            graph[i][i - 1 + row] = 1;
        if (i + 1 - row >= 0 && x + 1 <= row && y - 1 <= 0) if (!GetWorldValue(x + 1, y - 1)) 
            graph[i][i + 1 - row] = 1;
        if (i - 1 - row >= 0 && x - 1 <= 0 && y - 1 <= 0) if (!GetWorldValue(x - 1, y - 1)) 
            graph[i][i - 1 - row] = 1;
    }

    return graph;
}

int World::extraer_min(std::vector<int> dist, std::vector<bool> visit) {
    int min = __INT_MAX__, min_index;
    for (unsigned int v = 0; v < dist.size(); v++) {
        if (dist[v] <= min && visit[v] == false)
            min = dist[v], min_index = v;
    }
    return min_index;
}

/* bool 
World::IsInSet(const Cell& c, const std::vector<Cell>& s){
    for(unsigned int i = 0; i < s.size(); i++)
        if(s[i].getX()==c.getX() && s[i].getY()==c.getY())
            return true;

    return false;
}

void 
World::ReconstruirCamino(std::vector<Cell> &v, Cell actual, Cell I){
    Cell a = actual;
    v.push_back(a);
    while(a.getX() != I.getX() || a.getY() != I.getY()) {           //Mientras no llegue a la Cell inicial
        a = world[static_cast<unsigned int>(a.getPadre().first)][static_cast<unsigned int>(a.getPadre().second)];
        v.push_back(a);
    }
}

void 
World::CambiarHeuristica(bool opt){
    //delete heuristica_;
    if(opt){
        //Manhattan
        heuristica_ = new d_manhattan();
    }
    else{
        //Euclidea
        heuristica_ = new d_euclidea();
    }
}
std::vector<Cell> 
World::Astar(unsigned int xInicio, unsigned int yInicio, unsigned int xFinal, unsigned int yFinal){

    std::vector<std::vector<int>> graph = AdjacencyGraph4();

    std::vector<Cell> result;     // Almacena el camino optimo
    std::vector<Cell> setAbierto; //adyacentes disponibles
    std::vector<Cell> setCerrado; //adyacentes no disponibles

    Cell& Inicial = world[xInicio][yInicio];
    Cell& Final = world[xFinal][yFinal];

    Inicial.setg_(0);                                                   //Cambiamos valores heuristicos de la primera Cell
    Inicial.setf_((*heuristica_)(Inicial, Final));

    setAbierto.push_back(Inicial);                                      //Setup completada
    contador++;

    while(!setAbierto.empty()){
        unsigned int winner = 0;
        for(unsigned int i = 0; i < setAbierto.size(); i++){            //Se busca la Cell con menor f_valor
            if(setAbierto[i].getf_() < setAbierto[winner].getf_())
                winner = i;
        }

        //Cell copia a la que tenemos en el mundo y en el set.
        Cell actual = world[setAbierto[winner].getX()][setAbierto[winner].getY()];

        if((actual.getX() == xFinal) && (yFinal == actual.getY())){     //Es la misma Cell -> Hemos llegado al final con camino óptimo
            ReconstruirCamino(result, actual, Inicial);
            return result;
        }

        setAbierto.erase(setAbierto.begin() + winner);                  //Cambiamos actual de set
        setCerrado.push_back(actual);

        for(int i = 0; i < actual.sizeVecinos(); i++){                  //Miramos los vecinos de la Cell actual
            int x = actual.getVecino(i).first;
            int y = actual.getVecino(i).second;
            Cell vecino = world[x][y];                              //Valor copia de la Cell vecina

            if(IsInSet(vecino, setCerrado))
                continue;

            int tent_g = actual.getg_() + 1; //Aumento coste en uno por desplazarme de nodo

            if(!IsInSet(vecino, setAbierto)){ //Comprobar si set esta en lista abierta
                setAbierto.push_back(vecino);
                contador++;
            }
            else if(tent_g >= vecino.getg_())
                continue;

            //Este camino es el mejor! Guárdalo
            world[vecino.getX()][vecino.getY()].setPadre(actual);
            world[vecino.getX()][vecino.getY()].setg_(tent_g);
            world[vecino.getX()][vecino.getY()].setf_(tent_g + (*heuristica_)(vecino, Final));
        }
    }
    return result;
}


void World::CaminoMinimo(unsigned int xInicio, unsigned int yInicio, unsigned int xFinal, unsigned int yFinal){

    long t0,t1;

    t0 = clock();
    std::vector<Cell> result = Astar(xInicio, yInicio, xFinal, yFinal);
    t1 = clock();

    double time = (double(t1-t0)/CLOCKS_PER_SEC);

    std::cout << "Tamano resultado: " << result.size() << std::endl << "Tiempo de ejecucion: " << time;
} */
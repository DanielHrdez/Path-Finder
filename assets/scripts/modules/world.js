import * as f from "./functions.js";

// Fichero que contiene la clase World
export default class World {
  // Contructor por defecto que pasa los parámetros de filas y columnas
  // Crea un array de arrays
  // Y por cada array, crea una fila y recorre cada array creando una columna
  constructor(row = 10, col = 10) {
    this.row = row;
    this.col = col;
    this.size = this.row * this.col;
    this.map = Array(this.row);
    let i = 0;
    var html = [];
    while (i < this.row) {
      this.map[i] = new Array(this.col).fill(0);
      html.push("<div class='row row" + i + "' solid grey'>");
      let j = 0;
      while (j < this.col) {
        if (this.size <= 150 * 150)
          html.push(
            "<div class='col col" +
              j +
              "' style='border: 1px solid grey'></div>"
          ); 
        else
          html.push(
            "<div class='col col" +
              j +
              "' style='border: 0px solid grey'></div>"
          );
        ++j;
      }
      html.push("</div>");
      ++i;
    }
    document.getElementById("table").innerHTML = html.join("");
  }

  // Método para crear Objetos de forma aleatoria
  // Resetea todos los obstáculos a 0, y de forma aleatoria si no había un objeto anteriormente, lo coloca
  // Si había uno vuelve a comprobar
  setRandObs(obs_percent = 0, vehicle = null) {
    let obs_qty = (this.size * obs_percent) / 100;
    for (let i = 0; i < this.row; i++)
      for (let j = 0; j < this.row; j++)
        if (this.map[i][j] == 1) {
          this.map[i][j] = 0;
          document
            .getElementsByClassName("row")
            [i].getElementsByClassName("col")[j].style.background = "white";
        }

    let trys = 0;

    for (let i = 0; i < obs_qty; i++) {
      let rand_row = f.getRandomInt(0, this.row);
      let rand_col = f.getRandomInt(0, this.col);

      if (
        this.map[rand_row][rand_col] ||
        (vehicle.x == rand_col && vehicle.y == rand_row) ||
        (vehicle.x_final == rand_col && vehicle.y_final == rand_row)
      ) {
        i--;
        trys++;
      } else {
        this.map[rand_row][rand_col] = 1;
        document
          .getElementsByClassName("row")
          [rand_row].getElementsByClassName("col")[rand_col].style.background =
          "black";
        trys = 0;
      }
      if (trys == 1000) return;
    }
  }

  // Elimina las filas y columnas
  clear() {
    if (this.row === undefined) this.row = 10;
    for (let i = 0; i < this.row; i++) $(".row" + i).remove();
  }
}

// Fichero que contiene la clase Vehiculo
export default class Vehicle {
  // Constructor por defecto pasando su x e y, y lo implementa en la visualización
  // Primero copia los parámetros e incluye la imagen del vehículo en la fila x y columna y
  constructor(x = 0, y = 0, world) {
    this.set(x, y, world);
  }

  set(x = 0, y = 0, world) {
    if (world.map[y][x] == 0) {
      this.x = x;
      this.y = y;

      let div = $(".row" + this.y + " > .col" + this.x);
      div.addClass("car");
      div.css({
        background:
          "url('./assets/img/car.svg') no-repeat center center #528BEB",
      });
    }
  }

  // Crea el final de donde la clase Vehiculo debe llegar y lo visualiza
  // Primero copia los parámetros e incluye la imagen del final en la fila x_final y columna y_final
  setfinal(x = 0, y = 0, world) {
    if (world.map[y][x] == 0) {
      this.x_final = x;
      this.y_final = y;

      let div = $(".row" + this.y_final + " > .col" + this.x_final);
      div.addClass("final");
      div.css({
        background:
          "url('./assets/img/final.svg') no-repeat center center #ff0000",
      });
    }
  }

  // Remueve la visualización del vehiculo
  clear() {
    let div = $(".row" + this.y + " > .col" + this.x);
    div.removeClass("car");
    div.css({
      background: "white",
    });
  }

  // Remueve la visualización del final del vehiculo
  clearfinal() {
    let div = $(".row" + this.y_final + " > .col" + this.x_final);
    div.removeClass("final");
    div.css({
      background: "white",
    });
  }
}

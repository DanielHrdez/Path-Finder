import World from "./modules/world.js";
import Vehicle from "./modules/vehicle.js";
import Algorithm from "./modules/algorithm.js";
import * as f from "./modules/functions.js";
import "./modules/jquery.js";

// Fichero donde está todo el funcionamiento de la interfaz
// Primero se importan los demas archivos JS y se declaran las variables globales

let alto = 10,
  ancho = 10;
let world = new World();
let vehicle = new Vehicle(0, alto / 2 - 1, world);
vehicle.setfinal(ancho - 1, alto / 2 - 1, world);
let id1 = setInterval(f.checkclickworld(world, vehicle));
// let id2 = setInterval(f.checkmovevehicle(vehicle, world));
// let id3 = setInterval(f.checkmovefinal(vehicle, world));

f.borderinterval();

// Declara la creación de la clase World con el cambio de los inputs ancho y alto y comprueba si clickas en él
// Primero limpia world por si hay uno previo, luego obtiene los valores de alto y ancho y crea el mundo
// Por último crea una función asíncrona para checkear si clickas en el mundo y nunca termina
let alto_ancho = document.querySelectorAll("#alto, #ancho");
for (let i = 0; i < alto_ancho.length; i++) {
  alto_ancho[i].addEventListener("change", () => {
    world.clear();

    alto = f.checkNaN($("#alto").val());
    ancho = f.checkNaN($("#ancho").val());

    world = new World(ancho, alto);
    let id1 = setInterval(f.checkclickworld(world, vehicle));
  });
}
// Controla los cambios del input del % de obstaculos y llama al método del mundo
document.getElementById("obstaculos_input").addEventListener("change", () => {
  let obstaculos = f.checkNaN(
    document.getElementById("obstaculos_input").value
  );
  world.setRandObs(obstaculos, vehicle);
});

// Controla los cambios del input de la posicion del vehiculo y crea el objeto vehiculo
$("#x_vehiculo, #y_vehiculo").on("change", () => {
  vehicle.clear();

  let x = f.checkNaN($("#x_vehiculo").val());
  let y = f.checkNaN($("#y_vehiculo").val());

  vehicle.set(x, y, world);
});

// Controla los cambios del input del destino final y los introduce en el método de vehiculo
$("#x_final, #y_final").on("change", () => {
  vehicle.clearfinal();

  let x = f.checkNaN($("#x_final").val());
  let y = f.checkNaN($("#y_final").val());

  vehicle.setfinal(x, y, world);
});

let check_grid = false;
document.getElementById("grid").addEventListener("click", () => {
  if (check_grid) {
    $(".col").css("border", "1px solid grey");
    check_grid = false;
  } else {
    $(".col").css("border", "0 solid grey");
    check_grid = true;
  }
});

let table = $("#table");
let table_cont = $("#table-container");
let size = 100;
table_cont.on("wheel", (e) => {
  if (e.originalEvent.deltaY !== 0) {
    var diffX =
      e.pageX -
      parseInt(table_cont.css("left")) -
      parseInt(table_cont.css("width")) / 2;
    var diffY =
      e.pageY -
      parseInt(table_cont.css("top")) -
      parseInt(table_cont.css("height")) / 2;
    diffX = ((-diffX / 10) * (size - 100) * 1.1) / 10;
    diffY = ((-diffY / 10) * (size - 100) * 1.1) / 10;
    if (e.originalEvent.deltaY < 0) {
      size += 10;
      table.css({
        transform: "scale(" + size + "%)",
        left: diffX,
        top: diffY,
      });
    } else {
      size -= 10;
      table.css({
        transform: "scale(" + size + "%)",
        left: diffX,
        top: diffY,
      });
    }
  }
});

table_cont.on("mousedown", (e) => {
  if (e.buttons == 2) {
    var relX = e.pageX;
    var relY = e.pageY;
    var prevX = parseInt(table.css("left").replace("px", ""));
    var prevY = parseInt(table.css("top").replace("px", ""));

    table_cont.on("mousemove", (e) => {
      var diffX = e.pageX - relX;
      var diffY = e.pageY - relY;

      table.css("left", prevX + diffX + "px");
      table.css("top", prevY + diffY + "px");
    });
  }
});

table_cont.on("mouseup", () => {
  table_cont.off("mousemove");
});

let is_fullscreen = false;

$(".fullscreen").on("click", () => {
  is_fullscreen = !is_fullscreen;
  if (is_fullscreen) {
    table_cont.css({
      position: "fixed",
      top: 0,
      right: 0,
      bottom: 0,
      left: 0,
      zIndex: 999,
      width: "100%",
      height: "100%",
    });
  } else {
    table_cont.css({
      position: "absolute",
      top: "7.5%",
      left: "40%",
      zIndex: 1,
      width: "45%",
      height: "90%",
    });
  }
});

let type_dir = 4,
  type_alg = 0,
  see_childs = false;

$(
  setInterval(() => {
    if (type_dir == 4) {
      $("#dir_4").css({ color: "blue" });
      $("#dir_8").css({ color: "black" });
    } else if (type_dir == 8) {
      $("#dir_8").css({ color: "blue" });
      $("#dir_4").css({ color: "black" });
    }
    if (type_alg == 0) {
      $(".Manhattan").css({ color: "blue" });
      $(".Euclidean").css({ color: "black" });
      $(".Chebyshev").css({ color: "black" });
    } else if (type_alg == 1) {
      $(".Manhattan").css({ color: "black" });
      $(".Euclidean").css({ color: "blue" });
      $(".Chebyshev").css({ color: "black" });
    } else if (type_alg == 2) {
      $(".Manhattan").css({ color: "black" });
      $(".Euclidean").css({ color: "black" });
      $(".Chebyshev").css({ color: "blue" });
    }
    if (check_grid) $("#grid").css({ color: "black" });
    else $("#grid").css({ color: "blue" });
    if (see_childs) $(".childs").css({ color: "blue" });
    else $(".childs").css({ color: "black" });
  })
);

$("#dir_4").on("click", () => {
  type_dir = 4;
});

$("#dir_8").on("click", () => {
  type_dir = 8;
});

$(".Manhattan").on("click", () => {
  type_alg = 0;
});

$(".Euclidean").on("click", () => {
  type_alg = 1;
});

$(".Chebyshev").on("click", () => {
  type_alg = 2;
});

$(".childs").on("click", () => {
  see_childs = !see_childs;
});

let interval,
  simulate_first_time = true;
document.getElementById("simular").addEventListener("click", () => {
  console.time("Algoritmo");
  if (!simulate_first_time) {
    clearInterval(interval);
    $(".col")
      .filter(function (index) {
        return (
          this.style.backgroundColor == "rgb(42, 219, 142)" ||
          this.style.backgroundColor == "rgb(200, 200, 200)"
        );
      })
      .css({
        "background-color": "white",
      });
  } else {
    $(".col")
      .filter(function (index) {
        return this.style.backgroundColor == "#528BEB";
      })
      .css({
        "background-color": "white",
      });
  }

  let alg = new Algorithm(world, vehicle),
    path = alg.A_star(type_dir, type_alg, see_childs);

  if (path == undefined) {
    document.getElementById("error").style.display = "inline";
  } else {
    document.getElementById("error").style.display = "none";
    path.shift();
    path.pop();

    let count = 0;
    interval = setInterval(() => {
      if (count >= path.length) clearInterval(interval);
      else {
        $(".row" + path[count].y + "> .col" + path[count].x).css({
          "background-color": "#2adb8e",
        });
        count++;
      }
    }, 4);
  }
  console.timeEnd("Algoritmo");
  simulate_first_time = false;
});

// Fichero creado para declarar todas las funciones de forma global y exportada

// Checkea si un número intero no es NaN (Not a Number), retorna undefined si lo es, si no, devuelve el número
export function checkNaN(num) {
  if (Number.isNaN(parseInt(num))) return undefined;
  return parseInt(num);
}

// Checkea si estas clickando en las celdas del tablero o arrastrando el cursor y lo cambia de color
// Para cada celda lo cambia de color en caso de ser click_izq o el mouse salga de la celda pulsando el click izq
export function checkclickworld(world) {
  for (let j = 0; j < world.col; j++) {
    setTimeout(() => {
      $('.col' + j).on("mouseout", function (e) {
        if (e.buttons == 1) {
          let i = $(this).parent().attr('class').replace('row row', '');
          let current = $('.row' + i + ' > .col' + j);
          if (!current.hasClass('car') && !current.hasClass('final')) {
            if (world.map[i][j] == 0) {
              current.css('background-color', 'black');
              world.map[i][j] = 1;
            } else {
              current.css('background-color', 'white');
              world.map[i][j] = 0;
            }
          }
        }
      });

      $('.col' + j).on("click", function () {
        let i = $(this).parent().attr('class').replace('row row', '');
        let current = $('.row' + i + ' > .col' + j);
        if (!current.hasClass('car') && !current.hasClass('final')) {
          if (world.map[i][j] == 0) {
            current.css('background-color', 'black');
            world.map[i][j] = 1;
          } else {
            current.css('background-color', 'white');
            world.map[i][j] = 0;
          }
        }
      });
    }, 10);
  }
}

// // Checkea si estas clickando en las celdas del tablero o arrastrando el cursor y lo cambia de color
// // Para cada celda lo cambia de color en caso de ser click_izq o el mouse salga de la celda pulsando el click izq
// export function checkmovevehicle(vehicle, world) {
//   $('.car').on("mouseout", function (e) {
//     if (e.buttons == 1) {
//       if ((vehicle.x != j || vehicle.y != i) && 
//         (vehicle.x_final != j || vehicle.y_final != i)) {
//         if (world.map[i][j] == 0) {
//           current.css('background-color', 'black');
//           world.map[i][j] = 1;
//         } else {
//           current.css('background-color', 'white');
//           world.map[i][j] = 0;
//         }
//       }
//     }
//   });
// }

// // Checkea si estas clickando en las celdas del tablero o arrastrando el cursor y lo cambia de color
// // Para cada celda lo cambia de color en caso de ser click_izq o el mouse salga de la celda pulsando el click izq
// export function checkmovefinal(vehicle, world) {
//   $('.car').on("mouseout", function (e) {
//     if (e.buttons == 1) {
//       let i = $(this).parent().parent().attr('class').replace('row row', '');
//       let j = $(this).parent().attr('class').replace('col col', '');
//       let current = $('.row' + i + ' > .col' + j);
      
//       if ((vehicle.x != j || vehicle.y != i) && 
//         (vehicle.x_final != j || vehicle.y_final != i)) {
//         if (world.map[i][j] == 0) {
//           current.css('background-color', 'black');
//           world.map[i][j] = 1;
//         } else {
//           current.css('background-color', 'white');
//           world.map[i][j] = 0;
//         }
//       }
//     }
//   });
// }

// Crea un número aleatorio entre min y max
export function getRandomInt(min, max) {
  return Math.floor(Math.random() * (max - min)) + min;
}

export function borderinterval() {
  setInterval(() => {
    setTimeout(() => {
      $('.car').css('background', 'url(./assets/img/car_blue.svg) no-repeat center center white')
      $('.final').css('background', 'url(./assets/img/final_red.svg) no-repeat center center white')
    }, 1000);
    setTimeout(() => {
      $('.car').css('background', 'url(./assets/img/car.svg) no-repeat center center #528BEB')
      $('.final').css('background', 'url(./assets/img/final.svg) no-repeat center center #ff0000')
    }, 2000);
  }, 2000)
}
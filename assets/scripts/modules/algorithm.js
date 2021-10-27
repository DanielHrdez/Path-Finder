import Node from "./node.js";

export default class Algorithm {
  constructor(world, vehicle) {
    this.world = world;
    this.vehicle = vehicle;
  }

  A_star(type_dir = 4, type_alg = 0, see_childs = false) {
    let x = this.vehicle.x;
    let y = this.vehicle.y;
    let fin_x = this.vehicle.x_final;
    let fin_y = this.vehicle.y_final;

    var root = new Node(null, { x, y });
    var end = new Node(null, { x: fin_x, y: fin_y });

    let open_list = [];
    let closed_list = [];

    open_list.push(root);
    while (open_list.length > 0) {
      let curr_index = 0,
        index = 0,
        curr_node = open_list[0];
      for (let item of open_list) {
        if (item.f < curr_node.f) {
          curr_node = item;
          curr_index = index;
        }
        index++;
      }

      open_list.splice(curr_index, 1);
      closed_list.push(curr_node);

      if (curr_node.is_equal(end)) {
        let path = [];
        let current = curr_node;
        while (current != null) {
          path.push(current.pos);
          current = current.parent;
        }
        return path.reverse();
      }

      let children = [],
        pos = [];
      if (type_dir == 4)
        pos = [
          { x: -1, y: 0 },
          { x: 0, y: -1 },
          { x: 1, y: 0 },
          { x: 0, y: 1 },
        ];
      else
        pos = [
          { x: -1, y: 0 },
          { x: 0, y: -1 },
          { x: 1, y: 0 },
          { x: 0, y: 1 },
          { x: -1, y: -1 },
          { x: 1, y: -1 },
          { x: 1, y: -1 },
          { x: 1, y: 1 },
        ];

      let i = 0;
      for (let new_pos of pos) {
        let eq1 = false,
          eq2 = false;
        let node_pos = {
          x: curr_node.pos.x + new_pos.x,
          y: curr_node.pos.y + new_pos.y,
        };

        if (
          node_pos.x > this.world.col - 1 ||
          node_pos.x < 0 ||
          node_pos.y > this.world.row - 1 ||
          node_pos.y < 0
        )
          continue;

        if (this.world.map[node_pos.y][node_pos.x] != 0) continue;

        let new_node = new Node(curr_node, node_pos);
        children.push(new_node);
        let child = children[i];

        for (let closed of closed_list)
          if (child.is_equal(closed)) {
            eq1 = true;
            break;
          }

        if (!eq1) {
          child.g = curr_node.g + 1;
          if (type_alg == 0) child.h = this.Manhattan(child, end);
          else if (type_alg == 1) child.h = this.Euclidean(child, end);
          else if (type_alg == 2) child.h = this.Chebyshev(child, end);
          child.f = child.g + child.h;

          for (let open of open_list)
            if (child.is_equal(open) && child.g >= open.g) {
              eq2 = true;
              break;
            }

          if (!eq2) {
            open_list.push(child);
            if (see_childs) {
              setTimeout(() => {
                $(".row" + child.pos.y + "> .col" + child.pos.x).css({
                  "background-color": "rgb(200, 200, 200)",
                });
              }, 4);
            }
          }
        }
        i++;
      }
    }
    return;
  }

  Manhattan(child, end) {
    return (
      Math.abs(child.pos.x - end.pos.x) + Math.abs(child.pos.y - end.pos.y)
    );
  }

  Euclidean(child, end) {
    return Math.sqrt(
      (child.pos.x - end.pos.x) ** 2 + (child.pos.y - end.pos.y) ** 2
    );
  }

  Chebyshev(child, end) {
    return Math.max(
      Math.abs(child.pos.x - end.pos.x),
      Math.abs(child.pos.y - end.pos.y)
    );
  }
}

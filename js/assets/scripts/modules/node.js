export default class Node {
  constructor(parent = null, pos = null) {
    this.parent = parent;
    this.pos = pos;

    this.g = this.h = this.f = 0;
  }

  is_equal(other) {
    return this.pos.x == other.pos.x && this.pos.y == other.pos.y;
  }
}

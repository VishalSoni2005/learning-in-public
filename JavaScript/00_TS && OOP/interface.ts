interface Human {
  eye: boolean;
  think: boolean;
  name: string;
  age: number;
}

class User implements Human {
  constructor(
    public name: string,
    public age: number,
    public think: boolean,
    public eye: boolean
  ) {
    this.name = name;
    this.age = age;
    this.think = think;
    this.eye = eye;
  }
}

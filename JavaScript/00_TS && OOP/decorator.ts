function LogMethod(
  target: any,
  propertyKey: string,
  descriptor: PropertyDescriptor
) {
  console.log("Decorator initialized");
  return descriptor;
}
class Calculator {
  @LogMethod
  add(a: number, b: number) {
    return a + b;
  }
}

const calc = new Calculator();
console.log(calc.add(2, 3));
// Output:
// Calling add with [2, 3]
// 5

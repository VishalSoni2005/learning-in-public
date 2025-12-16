type oper = '+' | '-' | '*' | '/';

const calculator = (a: number, b: number, operation: oper): number => {
  if(operation === '+') return a + b;
  if(operation === '-') return a - b;
  if(operation === '*') return a * b;
  if(operation === '/') return a / b;
  return 0;
}

console.log(calculator(4, 2, '+'));

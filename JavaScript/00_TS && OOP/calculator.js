"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const calculator = (a, b, operation) => {
    if (operation === '+')
        return a + b;
    if (operation === '-')
        return a - b;
    if (operation === '*')
        return a * b;
    if (operation === '/')
        return a / b;
    return 0;
};
console.log(calculator(4, 2, '+'));
//# sourceMappingURL=calculator.js.map
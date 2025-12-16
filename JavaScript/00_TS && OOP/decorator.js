"use strict";
// Enable experimental decorators in tsconfig.json
// "experimentalDecorators": true
Object.defineProperty(exports, "__esModule", { value: true });
function Logger(constructor) {
    console.log("Class created:", constructor.name);
}
@Logger
class User {
    name;
    constructor(name) {
        this.name = name;
    }
}
// Output: "Class created: User"
const user = new User("Vishal");
console.log(user.name); // Output: "Vishal"
//# sourceMappingURL=decorator.js.map
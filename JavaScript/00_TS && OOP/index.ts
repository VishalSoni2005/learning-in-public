// class User {
//   constructor(public name: string, public email: string) {
//     this.email = email;
//     this.name = name;
//   }
// }

// let newUser = new User("Vishal", "vsoni0882");
// console.log(newUser.name);

const fetchData = async (url: string): Promise<Object> => {
  try {
    const response = await fetch(url);
    if (!response.ok) {
      throw new Error("Network response was not ok");
    }
    const data = await response.json();
    return data;
  } catch (error) {
    throw new Error("Failed to fetch data");
  } finally {
    return {};
  }
};

fetchData("https://jsonplaceholder.typicode.com/todos/1")
  .then((data) => console.log(data))
  .catch((error) => console.error(error));

// Output:
// { userId: 1, id: 1, title: 'delectus aut autem', completed: false }
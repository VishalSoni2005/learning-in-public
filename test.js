const fs = require('fs');

fs.readFile('./response.json', 'utf8', (err, data) => {
  if (err) {
    console.error('Error reading file:', err);
    return;
  }
  const response = JSON.parse(data);
  console.log("No of items: ",response.data.length);
});

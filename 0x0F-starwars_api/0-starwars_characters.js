#!/usr/bin/node
const request = require('request');

let characters = [];
const url = `https://swapi-api.hbtn.io/api/films/${process.argv.slice(2)}/`;
console.log(url);
request(url, function (error, response, body) {
  if (error || response.statusCode !== 200) console.log(error);

  else characters = JSON.parse(body).characters;
  console.log('hello');

  const size = Object.keys(characters).length;
  const array = Array(size).fill();

  let data = 0;

  for (let i = 0; i < size; i++) {
    request(characters[i], (error, response, body) => {
      if (error || response.statusCode !== 200) console.log(error);

      else {
        array[i] = JSON.parse(body).name;
        data++;
      }

      if (data === size) {
        for (let j = 0; j < size; j++) {
          console.log(array[j]);
        }
      }
    });
  }
});

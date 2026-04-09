const os = require('os');

let cpu_s = os.cpus();

let no_of_core = 0;

cpu_s.forEach(element =>{

    no_of_core ++;
    console.log("Logical core" + no_of_core + " : " ); 
    console.log(element);
});

console.log("Total number of logical cores : " + no_of_core);
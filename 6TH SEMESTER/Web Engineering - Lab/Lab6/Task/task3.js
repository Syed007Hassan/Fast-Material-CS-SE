const tablee = (num) => {
  for (let i = 1; i <= 10; i++) {
    console.log(num + " x " + i + " = " + num * i);
  }
};

const dis = prompt("ENTER A NUM:");
tablee(dis);

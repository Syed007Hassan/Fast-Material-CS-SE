let menu = document.querySelector("#menu-btn");
let navbar = document.querySelector(".navbar");

menu.onclick = () => {
  menu.classList.toggle("fa-times");
  navbar.classList.toggle("active");
};
document.querySelector("#search").onclick = () => {
  console.log("a");
  // document.querySelector(".login-form-container").classList.toggle("active");
  //location.href = "www.youtube.com";
};

document.querySelector("#aaa").addEventListener("click", function () {
  window.location.href = "check.html";
  return false
});

document.querySelector(".C").onclick = () => {
  console.log("a");
  document.querySelector(".login-form-container").classList.toggle("active");
};
document.querySelector("#close-login-form").onclick = () => {
  document.querySelector(".login-form-container").classList.remove("active");
};
window.onscroll = () => {
  if (window.scrollY > 0) {
    document.querySelector("header").classList.add("active");
  } else {
    document.querySelector("header").classList.remove("active");
  }
  menu.classList.remove("fa-times");
  navbar.classList.remove("active");
};
window.onload = () => {
  if (window.scrollY > 0) {
    document.querySelector("header").classList.add("active");
  } else {
    document.querySelector("header").classList.remove("active");
  }
};
document.querySelector(".home").onmousemove = (e) => {
  document.querySelectorAll(".home-parallax").forEach((ele) => {
    let speed = ele.getAttribute("data-speed");
    let x = (window.innerWidth - e.pageX * speed) / 90;
    let y = (window.innerHeight - e.pageY * speed) / 90;
    ele.style.transform = `translateX(${y}px) translateY(${x}px)`;
  });
};
document.querySelector(".home").onmouseleave = (e) => {
  document.querySelectorAll(".home-parallax").forEach((ele) => {
    ele.style.transform = `translateX(0px) translateY(0px)`;
  });
};

var swiper = new Swiper(".vehicles-slider", {
  slidesPerView: 1,
  spaceBetween: 20,
  loop: true,
  grabCursor: true,
  autoplay: {
    delay: 2500,
    disableOnInteraction: false,
  },
  pagination: {
    el: ".swiper-pagination",
    clickable: true,
  },
  breakpoints: {
    0: {
      slidesPerView: 1,
    },
    768: {
      slidesPerView: 2,
    },
    991: {
      slidesPerView: 3,
    },
  },
});
var swiper = new Swiper(".featured-slider", {
  slidesPerView: 1,
  spaceBetween: 20,
  loop: true,
  grabCursor: true,
  autoplay: {
    delay: 2500,
    disableOnInteraction: false,
  },
  pagination: {
    el: ".swiper-pagination",
    clickable: true,
  },
  breakpoints: {
    0: {
      slidesPerView: 1,
    },
    768: {
      slidesPerView: 2,
    },
    991: {
      slidesPerView: 3,
    },
  },
});

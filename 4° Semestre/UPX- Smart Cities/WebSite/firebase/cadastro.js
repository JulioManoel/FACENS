const email = 'admin'
const passoword = '123456'

// Import the functions you need from the SDKs you need
const firebase = require("firebase");
// Required for side-effects
require("firebase/firestore");

// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
    apiKey: "AIzaSyD7_VtaUGYCcgj986k88Yv9Sll6r5MJga0",
    authDomain: "validacao-estudo.firebaseapp.com",
    databaseURL: "https://validacao-estudo-default-rtdb.firebaseio.com",
    projectId: "validacao-estudo",
    storageBucket: "validacao-estudo.appspot.com",
    messagingSenderId: "57283915815",
    appId: "1:57283915815:web:8be73365549252fa86de02",
    measurementId: "G-86HN6B10P4"
};

// Initialize Firebase
firebase.initializeApp(firebaseConfig);

// Initialize Cloud Firestore and get a reference to the service
const db = firebase.firestore();

db.collection("UserAdmin").add({
    Email: email,
    Password: passoword,
})
.then((docRef) => {
    console.log("Document written with ID: ", docRef.id);
})
.catch((error) => {
    console.error("Error adding document: ", error);
});
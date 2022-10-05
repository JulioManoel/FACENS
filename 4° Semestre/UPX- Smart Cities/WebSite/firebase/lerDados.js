// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getFirestore, collection, getDocs } from "firebase/firestore"

export async function consultaFirebase(){
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
    const app = initializeApp(firebaseConfig);

    // Initialize Cloud Firestore and get a reference to the service
    const db = getFirestore(app);

    const querySnapshot = await getDocs(collection(db, "UserAdmin"));
    querySnapshot.forEach((doc) => {
        console.log(`${doc.id} => ${doc.data().Email}`);
    });

}


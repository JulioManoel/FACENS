const express = require('express')
const router = express.Router()
const consultaFirebase = require('../firebase/lerDados') //Le dados firebase

router.post('/',(req,res)=>{
    consultaFirebase(req.body.email, req.body.passoword, (verifica)=>{
        if(verifica == true){
            //Logado com Sucesso!
            req.session.email = req.body.email
            res.render('dashboard')
        } else {
            res.render('login')
        }
    })
})

router.post('/users',(req,res)=>{
    consultaFirebase(req.body.email, req.body.passoword, (verifica)=>{
        if(verifica == true){
            //Logado com Sucesso!
            req.session.email = req.body.email
            console.log("O meu email é: " + req.session.email)
            res.render('users')
        } else {
            res.render('login')
        }
    })
})

router.get('/', (req,res)=>{
    if(req.session.email){
        res.render('dashboard')
    } else{
        res.render('login')
    }
})

router.get('/users', (req,res)=>{
    if(req.session.email){
        res.render('users')
    } else{
        res.render('login')
    }
})

module.exports = router
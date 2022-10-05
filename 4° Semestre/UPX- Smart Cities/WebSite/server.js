const express = require('express')
const session = require('express-session')
const bodyParser = require('body-parser') //Permite receber via POST os dados
const consultaFirebase = require('./firebase/lerDados') //Le dados firebase
//let userRouter = require('./routes/router')

const port = 3000
var path = require('path')
const app = express()

app.use(session({
    secret:'fjvbdskjvbsdjkvbdskjvbdsjkvb', 
    proxy: true,
    resave: true, 
    saveUninitialized: true
}))

//app.use('/', userRouter)
app.use(bodyParser.urlencoded({extended:true}))
app.engine('html', require('ejs').renderFile)
app.set('view engine', 'html')
app.set('views', path.join(__dirname, '/views'))

app.post('/',(req,res)=>{
    consultaFirebase(req.body.email, req.body.passoword, (verifica)=>{
        if(verifica == true){
            //Logado com Sucesso!
            req.session.email = req.body.email
            console.log("O meu email é: " + req.session.email)
            res.render('dashboard')
        } else {
            res.render('login')
        }
    })
})

app.post('/users',(req,res)=>{
    consultaFirebase(req.body.email, req.body.passoword, (verifica)=>{
        if(verifica == true){
            //Logado com Sucesso!
            req.session.email = req.body.email
            res.render('users')
        } else {
            res.render('login')
        }
    })
})

app.get('/', (req,res)=>{
    if(req.session.email){
        res.render('dashboard')
    } else{
        res.render('login')
    }
})
app.get('/users', (req,res)=>{
    if(req.session.email){
        res.render('users')
    } else{
        res.render('login')
    }
})

app.listen(port, () => {
    console.log("Servidor Rodando")
})
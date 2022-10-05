const express = require('express')
const session = require('express-session')
 
//Permite receber via POST os dados


const port = 3000
var path = require('path')
const app = express()

var login = 'admin'
var passoword = '123456'

app.use(session({
    secret:'fjvbdskjvbsdjkvbdskjvbdsjkvb', 
    proxy: true,
    resave: true, 
    saveUninitialized: true
}))

app.use(urlencoded({extended:true}))
app.engine('html', require('ejs').renderFile)
app.set('view engine', 'html')
app.use('/public', express.static(join(__dirname, 'public')))
app.set('views', join(__dirname, '/views'))

app.post('/',(req,res)=>{
    console.log(typeof req.body.email)
    //consultaFirebase();
    if(req.body.email == email && req.body.passoword == passoword){
        //Logado com Sucesso!
        req.session.email = email
        res.render('dashboard')
    } else {
        res.render('login')
    }
})

app.get('/', (req,res)=>{
    if(req.session.login){
        res.render('dashboard')
    } else{
        res.render('login')
    }
})

app.listen(port, () => {
    console.log("Servidor Rodando")
})
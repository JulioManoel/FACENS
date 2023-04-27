import Express from 'express'
import { route } from './routes'
import mongoose from 'mongoose'

// Configuraçaõ MongoDB
mongoose.connect('mongodb://127.0.0.1:2017/ac2Parte1')
    .then(() => console.log('MongoDB Conectado com Sucesso'))
    .catch((error) => console.log(`Erro ao conectar com o banco: ${error}`))

// Configuração Express
const app = Express()
app.use(Express.json())
app.use(route)
app.listen(3000, () => console.log('Server Running on port 3000'))
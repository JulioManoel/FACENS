import express from 'express'
import { router } from './router'
import mongoose from 'mongoose'
import cors from 'cors'

const app = express()
app.use(express.json())
app.use(cors())
app.use(router)

mongoose.connect('mongodb://127.0.0.1:27017/AC2_parte2')
  .then(() => console.log('Conectado com Sucesso ao DB'))
  .catch(() => console.log('Erro ao Conectar com DB'))

app.listen(3000, () => console.log('server running on port 3000'))
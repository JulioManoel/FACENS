import express from "express"
import { route } from "./routes"
import mongoose from "mongoose"

const app = express()
app.use(express.json())

mongoose.connect('mongodb://127.0.0.1:27017/test')
app.use(route)
app.listen(3000, () => console.log('Server Running on port 3000'))
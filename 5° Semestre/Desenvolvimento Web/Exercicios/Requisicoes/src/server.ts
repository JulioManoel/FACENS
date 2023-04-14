import express from 'express'
import { Router, Request, Response} from 'express'
import { listUser } from './User'

const app = express()
const route = Router()
app.use(express.json())

route.get('/users', (req: Request, res: Response) => {
    res.json(listUser)
})
    
route.post('/users', (req: Request, res: Response) => {
    const message = req.body
    listUser.push({name: message.name, age: message.idade})
}) 

app.use(route)
app.listen(3000, () => console.log("Server Running on port 3000"))
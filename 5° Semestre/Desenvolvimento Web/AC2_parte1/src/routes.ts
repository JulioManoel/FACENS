import { Router, } from 'express'
import UserController from './controllers/UserController'

export const route = Router()
route.get('/users', UserController.list)
route.post('/user', UserController.create)
route.delete('/delethanos', UserController.delete)
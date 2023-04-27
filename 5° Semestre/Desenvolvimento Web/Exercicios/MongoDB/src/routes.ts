import { Router } from "express";
import UserController from "./controller/UserController";

export const route = Router()
route.get('/api/user', UserController.list)
route.post('/api/user', UserController.create)
route.patch('/api/user', UserController.update)
route.delete('/api/user', UserController.delete)
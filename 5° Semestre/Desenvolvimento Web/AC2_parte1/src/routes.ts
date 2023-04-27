import { Router, Request, Response } from 'express'

export const route = Router()
route.get('/', (request: Request, response: Response) => {
    response.json({ message: 'hello' })
})
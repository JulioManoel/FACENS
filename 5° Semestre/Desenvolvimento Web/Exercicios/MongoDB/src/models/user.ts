import mongoose, { Schema } from "mongoose";

const User = new Schema({
    name: { type: String, required: true }
})
export default mongoose.model('User', User)
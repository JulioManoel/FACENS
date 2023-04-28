import mongoose, { Schema } from "mongoose";

const User = new Schema({
    name: { type: String, require: true }
})

export default mongoose.model('User', User)
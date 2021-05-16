const mongoose = require('mongoose')
const {find_date,find_day,find_hour,find_minutes,find_seconds} = require('../utils/date_info')


const dataSchema = new mongoose.Schema({
    day : {
        type : String,
        require :true,
        
    },
    date : {
        type : Date,
        require:true
    },
    time : {
        type : String,
        require : true
    },
    status : {
        type : String,
        require:true
    },
    hour : {
        type : Number,
        require: true
    },
    min : {
        type:Number,
        require:true
    },

        
    

})

const data = mongoose.model('data',dataSchema);
module.exports = data;


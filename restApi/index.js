const express = require('express');
const mongoose = require('mongoose')
const routes = require('./routes/data_route')
const {find_date,find_day,find_time,find_hour,find_minutes} = require('./utils/date_info')
const app = express();

const url = process.env.URL || "mongodb+srv://mongo_database:mongo_db_1999@cluster0.yqcqg.mongodb.net/iot_db?retryWrites=true&w=majority";
//"mongodb://localhost:27017/test-db"
// "mongodb+srv://mongo_database:mongo_db_1999@cluster0.yqcqg.mongodb.net/iot_db?retryWrites=true&w=majority";
const port = process.env.PORT || 3000;

app.use(express.json())
app.use(express.urlencoded())

app.use('/iot',routes);


app.listen(port,()=>{
    
    mongoose.connect(url,{useNewUrlParser: true, useCreateIndex:true},(err)=>{
        if(err)
        {
            return console.log(err)
        }
        console.log("server is up on "+port);
        let dt = new Date();
        dt.setDate( dt.getDate() - 5 );
        console.log( dt)
    
    })
    
})


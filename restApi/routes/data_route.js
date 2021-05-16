const express = require('express');
const router = express.Router();
//const {find_date,find_day,find_time,find_hour,find_minutes} = require('../utils/date_info');
const Data= require('../models/data')

router.post('/', async(req,res)=>{
    const data = new Data(req.body)
    try{
     await data.save();
     res.status(201).json({
         Msg : " Data saved"
     })
    }catch(err){
        console.log(err)
        res.status(400).json({
            Msg : "Server error"
        })
    }

})

router.get('/',async(req,res)=>{

    if(req.query.days)
    {
        try{
            const days  = parseInt(req.query.days); 
            let dt = new Date();
             dt.setDate( dt.getDate() - days);
             //Date("2021-04-29")
             const data = await Data.find({date : { $gt : dt }}).sort('date')
             const count = await Data.find({date : { $gt : dt }}).sort('date').count()
            res.status(200).json({
                data,
                count
            })
            }catch(err){
                console.log(err)
                res.status(400).json({
                    Msg : "error"
                })
            }

    } else if(req.query.date)
    {
        try{

            // let dt = new Date(req.query.date);
            //  dt.setDate( dt.getDate() - 5);
             const dt = new Date(req.query.date);
             const data = await Data.find({date : { $gte : dt }}).sort('date')
             const count = await Data.find({date : { $gte : dt }}).sort('date').count()
            res.status(200).json({
                data,
                count,
                date : req.query.date
            })
            }catch(err){
                console.log(err)
                res.status(400).json({
                    Msg : "error"
                })
            }
    }else{
        try{
            //let dt = new Date();
            // dt.setDate( dt.getDate() - 5);
             //Date("2021-04-29")
             const data = await Data.find({}).sort('date')
             const count = await Data.find({}).sort('date').count()
            res.status(200).json({
                data,
                count
            })
            }catch(err){
                console.log(err)
                res.status(400).json({
                    Msg : "error"
                })
            }
        }
    
})




module.exports = router
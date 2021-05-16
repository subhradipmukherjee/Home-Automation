const date = new Date()
const find_day = ()=>{
    switch (date.getDay()) {
        case 0:
          return "Sunday";
          break;
        case 1:
          return "Monday";
          break;
        case 2:
          return "Tuesday";
          break;
        case 3:
          return "Wednesday";
          break;
        case 4:
          return "Thursday";
          break;
        case 5:
          return"Friday";
          break;
        case 6:
          return "Saturday";
      }

}

const find_date = ()=>{
    var d = date.getDate();
    var month = date.getMonth() + 1; 
    var year = date.getFullYear();
    var dateStr = d + "/" + month + "/" + year;
    return dateStr
}

const find_time =()=>{
    const h = date.getHours()
    const m = date.getMinutes()
    const s = date.getSeconds()

    const time_str = h + ":" + m + ":" + s
    return time_str
}
const find_hour = ()=>{
    return date.getHours()
}

const find_minutes = ()=>{
    return date.getMinutes()
}

const find_seconds = ()=>{
    return date.getSeconds()
}
module.exports = {
    find_date,
    find_day,
    find_time,
    find_hour,
    find_minutes,
    find_seconds
}

// muc do hieu biet can ban ve json  

// nhan xet : json no chi luu cac gia tri thanh mot string va de dang van chuyen data do di thoi chu thuc ra khong co gi ca
var student = 
[
        {
        id :125458,
        name:"ngokimquy",
        address:"ho chi minh city"
        },

        {
        id :125458,
        name:"ngokimquy",
        address:"ho chi minh city"
        },

        {
        id :125458,
        name:"ngokimquy",
        address:"ho chi minh city"
        },
]
var studentjs= JSON.stringify(student);
console.log(student[0].id);
console.log(studentjs);
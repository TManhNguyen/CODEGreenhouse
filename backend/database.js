const { Pool } = require('pg')

const database = new Pool({
  connectionString: process.env.DATABASE_URL,
  ssl: { rejectUnauthorized: false }
  // user: 'hpqtfgknghfmfm',
  // host: 'ec2-54-208-139-247.compute-1.amazonaws.com',
  // database: 'dcmfe60db6ju70',
  // password: 'e4bbdb003284c071f8cc8e1e2eed47b2d286ba1c5379b3df1f54b12d37cd4d7b',
  // port: 5432,
})

module.exports = { database }

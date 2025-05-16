const express = require('express');
const oracledb = require('oracledb');
const app = express();
app.use(express.json());
const cors = require('cors');
app.use(cors());

// Endpoint to insert data into the cart
app.post('/addToCart', async (req, res) => {
    let connection;
    try {
        connection = await oracledb.getConnection({
            user: "system",
            password: "oracle123",
            connectString: "localhost:1521/ORCLPDB"
        });

        // Check if the item is already in the cart
        const { rows } = await connection.execute(
            `select * from cart where item_id = :item_id`,
            { item_id: req.body.item_id }
        );

        if (rows.length > 0) {
            // If the item is already in the cart, increase the quantity by 1
            await connection.execute(
                `update cart set quantity = quantity + 1 where item_id = :item_id`,
                { item_id: req.body.item_id }
            );
        } else {
            // If the item is not in the cart, insert it with a quantity of 1
            await connection.execute(
                `insert into cart values(:item_id, 1)`,
                { item_id: req.body.item_id }
            );
        }

        await connection.execute(`commit`);
        res.json({ message: 'Successfully updated cart' });
    } catch (err) {
        console.error(err);
        res.status(500).json({ error: err.message });
    } finally {
        if (connection) {
            try {
                await connection.close();
            } catch (err) {
                console.error(err);
            }
        }
    }
});

// Endpoint to truncate the cart
app.post('/clearCart', async (req, res) => {
    let connection;
    try {
        connection = await oracledb.getConnection({
            user: "system",
            password: "oracle123",
            connectString: "localhost:1521/ORCLPDB"
        });

        const result = await connection.execute(
            `truncate table cart`
        );
        await connection.execute(`commit`);

        res.json({ message: 'Successfully truncated cart', result });
    } catch (err) {
        console.error(err);
        res.status(500).json({ error: err.message });
    } finally {
        if (connection) {
            try {
                await connection.close();
            } catch (err) {
                console.error(err);
            }
        }
    }
});



// Endpoint to get data from the cart
app.get('/getCart', async (req, res) => {
    let connection;
    try {
        connection = await oracledb.getConnection({
            user: "system",
            password: "oracle123",
            connectString: "localhost:1521/ORCLPDB"
        });
        const val = await connection.execute(
            `select sum(price*quantity) from cart join items on cart.item_id=items.item_id`
        )
        const total = val.rows[0][0]; // Access the sum
        const result = await connection.execute(
            `select item_name,price,quantity from cart join items on cart.item_id = items.item_id`
        );

        res.json({ message: 'Successfully retrieved cart', result, total });
    } catch (err) {
        console.error(err);
        res.status(500).json({ error: err.message });
    } finally {
        if (connection) {
            try {
                await connection.close();
            } catch (err) {
                console.error(err);
            }
        }
    }
});
app.post('/getCustomer', async (req, res) => {
    let connection;
    try {
        connection = await oracledb.getConnection({
            user: "system",
            password: "oracle123",
            connectString: "localhost:1521/ORCLPDB"
        });

        const { email, password } = req.body;
        const result = await connection.execute(
            `SELECT * FROM CLIENT join clientmail on client.client_id=clientmail.client_id WHERE EMAIL = :email AND PASSWORD = :password`,
            [email, password]
        );
        if (result.rows.length > 0) {
            res.json({ message: 'User exists', result: result.rows[0] });
        } else {
            res.status(404).json({ message: 'Customer not found' });
        }
    } catch (err) {
        console.error(err);
        res.status(500).json({ error: err.message });
    } finally {
        if (connection) {
            try {
                await connection.close();
            } catch (err) {
                console.error(err);
            }
        }
    }
});
app.post('/setCustomer', async (req, res) => {
    let connection;
    try {
        connection = await oracledb.getConnection({
            user: "system",
            password: "oracle123",
            connectString: "localhost:1521/ORCLPDB"
        });

        const { name, phone, email, password } = req.body;
        const result = await connection.execute(
            `INSERT INTO CLIENT (NAME, PASSWORD) VALUES (:name, :password) RETURNING CLIENT_ID INTO :id`,
            { name, password, id: { dir: oracledb.BIND_OUT, type: oracledb.NUMBER } }
        );
        const clientId = result.outBinds.id[0];

        await connection.execute(
            `INSERT INTO CLIENTPHONE (CLIENT_ID, PHONE) VALUES (:clientId, :phone)`,
            { clientId, phone }
        );

        await connection.execute(
            `INSERT INTO CLIENTMAIL (CLIENT_ID, EMAIL) VALUES (:clientId, :email)`,
            { clientId, email }
        );
        await connection.execute(
            `commit`
        )
        if (result.rowsAffected > 0) {
            console.log('User created');
            res.json({ message: 'User created', result: result.rowsAffected });
        } else {
            res.status(404).json({ message: 'User not created' });
        }
    } catch (err) {
        console.error(err);
        res.status(500).json({ error: err.message });
    } finally {
        if (connection) {
            try {
                await connection.close();
            } catch (err) {
                console.error(err);
            }
        }
    }
});
app.listen(3000, () => console.log('Server started on port 3000'));
CREATE TABLE IF NOT EXISTS [ssh-keys] (
    path     TEXT NOT NULL
                  UNIQUE
                  PRIMARY KEY,
    nickname TEXT UNIQUE,
    password TEXT
);

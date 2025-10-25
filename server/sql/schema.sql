-- rocket_designs table
CREATE TABLE IF NOT EXISTS rocket_designs (
    id UUID PRIMARY KEY,
    design_name TEXT NOT NULL,
    description TEXT
);

-- rocket_design_images table
CREATE TABLE IF NOT EXISTS rocket_design_images (
    id SERIAL PRIMARY KEY,
    rocket_id UUID REFERENCES rocket_designs(id) ON DELETE CASCADE,
    url TEXT NOT NULL,
    filename TEXT NOT NULL
);


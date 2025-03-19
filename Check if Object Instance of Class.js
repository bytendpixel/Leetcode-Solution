var checkIfInstanceOf = function(obj, classFunction) {
    if (obj == null || typeof classFunction !== "function") return false;
    
    if (obj instanceof classFunction) return true;
    if (classFunction == Object) return true;

    if (
        (typeof obj === "number" && classFunction === Number) ||
        (typeof obj === "bigint" && classFunction === BigInt) ||
        (typeof obj === "string" && classFunction === String) ||
        (typeof obj === "boolean" && classFunction === Boolean) ||
        (typeof obj === "symbol" && classFunction === Symbol)
    ) {
        return true;
    }

    return false;
};

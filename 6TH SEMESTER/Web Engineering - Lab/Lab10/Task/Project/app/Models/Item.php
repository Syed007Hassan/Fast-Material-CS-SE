<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Item extends Model
{
    use HasFactory;

    protected $table = 'items'; // Set the table name to 'items'

    protected $fillable = [ // Define the fillable attributes
        'name',
        'price',
    ];
}

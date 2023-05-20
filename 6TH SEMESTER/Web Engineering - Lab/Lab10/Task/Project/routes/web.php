<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\ProductController;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group that
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/', [ProductController::class, 'index'])
    ->name('products.index');

Route::get('/create', [ProductController::class, 'create'])
    ->name('products.create');

Route::post('/store', [ProductController::class, 'store'])
    ->name('products.store');

Route::get('/show/{product}', [ProductController::class, 'show'])
    ->name('products.show');

Route::get('/edit/{product}', [ProductController::class, 'edit'])
    ->name('products.edit');

Route::put('/update/{product}', [ProductController::class, 'update']);

Route::delete('/destroy/{product}', [ProductController::class, 'destroy'])

    ->name('products.destroy');



// Route::get('/', function () {
//     return view('welcome');
// });


Route::get('/fake', [ProductController::class, 'fake']);


use App\Models\Item;

Route::get('/create-item', function () {
    $item = new Item;
    $item->name = 'Test Item2';
    $item->price = 9.999;
    $item->save();

    return 'Item created';
});



Route::get('/dashboard', function () {
    return view('dashboard');
})->middleware(['auth'])->name('dashboard');

<?php

namespace App\Http\Controllers;

use App\Models\Profile;
use Illuminate\Http\RedirectResponse;
use Illuminate\Http\Request;
use Illuminate\Http\Response;
use Illuminate\View\View;

class ProfileController extends Controller
{
    public function index(): View
    {
        $profiles = Profile::all();

        return view('profiles.index', compact('profiles'));
    }


    public function show(Profile $profile): View
    {
        return view('profiles.show', compact('profile'));
    }
}
